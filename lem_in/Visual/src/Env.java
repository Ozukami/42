
import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Scanner;

import javafx.animation.Animation;
import javafx.animation.Animation.Status;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.animation.TranslateTransition;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Rectangle2D;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;
import javafx.util.Duration;

public class Env {

	private LinkedList<Room> roomList;
	private LinkedList<Pipe> pipeList;
	private LinkedList<Move> moveList;
	private Timeline timeLine;
	private TranslateTransition tT;
	private Stage window;
	private Scene scene;
	private Group root;
	private Group stats;
	private Label nbAnt;
	private Label turn;
	private Group map_container;
	private Group map;
	private Rectangle background;
	private VBox pipes;
	private ScrollPane sp;
	private int x_min = 0, y_min = 0;
	private int x_max = 0, y_max = 0;
	private int ppe_x = 3, ppe_y = 3;
	private int ant = 0;
	private int ant_end = 0;
	private int nb_turn = 0;
	final ImageView imageView = new ImageView(new Image("/ant.png"));
	private Animation animation;

	public Env(Stage window) {
		this.roomList = new LinkedList<Room>();
		this.pipeList = new LinkedList<Pipe>();
		this.moveList = new LinkedList<Move>();
		this.timeLine = new Timeline();
		this.tT = new TranslateTransition(new Duration(750));
		this.getData();
		// this.getDataFromFile();

		this.setWindow(window);
		this.scene = new Scene(root = new Group(), ((this.x_max >= this.y_max) ? 1080 : 720),
				((this.y_max >= this.x_max) ? 1080 : 720), Color.GREY);
		this.map_container = new Group();
		this.map = new Group();
		this.background = new Rectangle(1080, 1080, Color.GREY);
		this.background.widthProperty().bind(this.scene.widthProperty());
		this.background.heightProperty().bind(this.scene.heightProperty());

		this.initPipes();
		this.initSP();

		this.root.getChildren().addAll(this.map_container, this.sp);
		this.map_container.getChildren().addAll(this.background, this.map);

		this.nbAnt = new Label(String.format("Ant: %d/%d", ant_end, ant));
		this.turn = new Label(String.format("Turn: %d", 0));
		this.stats = new Group(this.nbAnt, this.turn);

		this.nbAnt.setScaleX(2);
		this.nbAnt.setScaleY(2);
		this.turn.setScaleX(2);
		this.turn.setScaleY(2);
		this.turn.setLayoutX((this.nbAnt.getText().length() * 14));
		this.stats.setLayoutX(40);
		this.stats.setLayoutY(20);

		this.root.getChildren().add(stats);

		this.map.requestFocus();

		imageView.setScaleX(imageView.getScaleX() - 0.8);
		imageView.setScaleY(imageView.getScaleY() - 0.8);
		imageView.setVisible(false);

		map.getChildren().add(imageView);

		int t = 1000;
		for (Move move : this.moveList) {
			this.timeLine.getKeyFrames().add(new KeyFrame(new Duration(t), actionEvent -> {
				if (move.getFromRoom().getRole() == 0) {
					move.getFromRoom().getRectangle().setFill(Color.BLUE);
				}

				this.turn.setText(String.format("Turn: %d", nb_turn = move.getTurn()));
				int x1 = move.getFromRoom().getX_mid();
				int y1 = move.getFromRoom().getY_mid();
				int x2 = move.getToRoom().getX_mid();
				int y2 = move.getToRoom().getY_mid();

				if (x1 < x2 && y1 < y2)
					imageView.setRotate(135);
				else if (x1 > x2 && y1 > y2)
					imageView.setRotate(-45);
				else if (x1 > x2 && y1 < y2)
					imageView.setRotate(-135);
				else if (x1 < x2 && y1 > y2)
					imageView.setRotate(45);
				else if (x1 < x2 && y1 == y2)
					imageView.setRotate(90);
				else if (x1 > x2 && y1 == y2)
					imageView.setRotate(-90);
				else if (x1 == x2 && y1 < y2)
					imageView.setRotate(180);
				else if (x1 == x2 && y1 > y2)
					imageView.setRotate(0);

				imageView.setLayoutX(move.getFromRoom().getX_mid());
				imageView.setLayoutY(move.getFromRoom().getY_mid());

				imageView.setTranslateX(-256);
				imageView.setTranslateY(-256);

				imageView.setViewport(new Rectangle2D(0, 0, 512, 512));

				animation = new SpriteAnimation(imageView, Duration.millis(350), 6, 2, 0, 0, 512, 512);
				animation.setCycleCount(Animation.INDEFINITE);

				imageView.setVisible(true);
				imageView.toFront();
				animation.play();

				tT.setNode(imageView);
				tT.setByX(move.getToRoom().getRectangle().getX() - move.getFromRoom().getRectangle().getX());
				tT.setByY(move.getToRoom().getRectangle().getY() - move.getFromRoom().getRectangle().getY());
				tT.play();
				tT.setOnFinished(new EventHandler<ActionEvent>() {
					@Override
					public void handle(ActionEvent event) {
						imageView.setVisible(false);
						animation.stop();
						if (move.getToRoom().getRole() == 0)
							move.getToRoom().getRectangle().setFill(Color.BLUEVIOLET);
						if (move.getToRoom().getRole() == 2)
							nbAnt.setText(String.format("Ant: %d/%d", ++ant_end, ant));
						if (ant == ant_end)
							new PopUp(ant_end, nb_turn);
					}
				});
			}));
			t += 1000;
		}

		root.setOnKeyPressed(new EventHandler<KeyEvent>() {
			@Override
			public void handle(KeyEvent event) {
				if (event.getCode() == KeyCode.SPACE) {
					if (timeLine.getStatus() == Status.RUNNING) {
						timeLine.pause();
						if (tT.getStatus() == Status.RUNNING)
							tT.pause();
					} else if (!timeLine.getCurrentTime().equals(Duration.seconds(moveList.size())))
						timeLine.playFrom(timeLine.getCurrentTime());
					if (tT.getStatus() == Status.PAUSED)
						tT.play();
				}
			}
		});
		timeLine.play();
	}

	private void getData() {
		String line;
		String split[];
		int role;
		int turn = 1;
		Scanner sc = new Scanner(System.in);
		line = sc.nextLine();
		if (line.startsWith("Error")) {
			System.out.println(line);
			System.exit(0);
		}
		this.ant = Integer.parseInt(line);
		while (sc.hasNext()) {
			line = sc.nextLine();
			role = 0;
			while (line.startsWith("#")) {
				role = (line.equals("##start")) ? 1 : ((line.equals("##end")) ? 2 : 0);
				line = sc.nextLine();
			}
			if (line.startsWith("L")) {
				String split2[];
				Room fromRoom;
				split = line.split(" ");
				for (String move : split) {
					split2 = move.substring(1, move.length()).split("-");
					fromRoom = this.getStart();
					for (Move elem : moveList) {
						if (elem.getAnt_id() == Integer.parseInt(split2[0]))
							fromRoom = elem.getToRoom();
					}
					moveList.add(new Move(turn, Integer.parseInt(split2[0]), this.getRoom(split2[1]), fromRoom));
				}
				turn++;
			} else if (line.contains(" ")) {
				split = line.split(" ");
				roomList.add(new Room(split[0], Integer.parseInt(split[1]), Integer.parseInt(split[2]), 40, 40, role));
				this.x_min = Math.min(this.x_min, Integer.parseInt(split[1]));
				this.y_min = Math.min(this.y_min, Integer.parseInt(split[2]));
				this.x_max = Math.max(this.x_max, Integer.parseInt(split[1]));
				this.y_max = Math.max(this.y_max, Integer.parseInt(split[2]));
			} else if (line.contains("-")) {
				split = line.split("-");
				this.pipeList.add(new Pipe(this.getRoom(split[0]), this.getRoom(split[1])));
			}
		}
		sc.close();
	}

	@SuppressWarnings("unused")
	private void getDataFromFile() {
		String line;
		String split[];
		int role;
		int turn = 1;

		try {
			Scanner sc = new Scanner(new File(System.getProperty("user.dir") + "../../tests/test2"));
			this.ant = sc.nextInt();
			while (sc.hasNext()) {
				line = sc.nextLine();
				role = 0;
				while (line.startsWith("#")) {
					role = (line.equals("##start")) ? 1 : ((line.equals("##end")) ? 2 : 0);
					line = sc.nextLine();
				}
				if (line.startsWith("L")) {
					String split2[];
					Room fromRoom;
					split = line.split(" ");
					for (String move : split) {
						split2 = move.substring(1, move.length()).split("-");
						fromRoom = this.getStart();
						for (Move elem : moveList) {
							if (elem.getAnt_id() == Integer.parseInt(split2[0]))
								fromRoom = elem.getToRoom();
						}
						moveList.add(new Move(turn, Integer.parseInt(split2[0]), this.getRoom(split2[1]), fromRoom));
					}
					turn++;
				} else if (line.contains(" ")) {
					split = line.split(" ");
					roomList.add(
							new Room(split[0], Integer.parseInt(split[1]), Integer.parseInt(split[2]), 40, 40, role));
					this.x_min = Math.min(this.x_min, Integer.parseInt(split[1]));
					this.y_min = Math.min(this.y_min, Integer.parseInt(split[2]));
					this.x_max = Math.max(this.x_max, Integer.parseInt(split[1]));
					this.y_max = Math.max(this.y_max, Integer.parseInt(split[2]));
				} else if (line.contains("-")) {
					split = line.split("-");
					this.pipeList.add(new Pipe(this.getRoom(split[0]), this.getRoom(split[1])));
				}
			}
			sc.close();
		} catch (FileNotFoundException e) {
			System.out.println("No such file or directory");
			System.exit(0);
		}
	}

	private void initPipes() {
		String cssLayout = "-fx-border-color: darkgrey;" + "\n-fx-border-insets: 5;\n" + "-fx-border-width: 3;\n"
				+ "-fx-background-color: darkgrey;\n";
		this.pipes = new VBox(5);
		this.pipes.setStyle(cssLayout);
		this.pipes.setLayoutX(20);
		this.pipes.setLayoutY(20);
		this.pipes.setMinHeight(100);
		this.pipes.setMinWidth(146);
	}

	private void initSP() {
		String cssLayout = "-fx-border-color: darkgrey;" + "\n-fx-border-insets: 5;\n" + "-fx-border-width: 3;\n"
				+ "-fx-background-color: darkgrey;\n";
		this.sp = new ScrollPane(pipes);
		this.sp.setLayoutX(20);
		this.sp.setLayoutY(60);
		this.sp.setHbarPolicy(ScrollPane.ScrollBarPolicy.NEVER);
		this.sp.setStyle(cssLayout);
		this.sp.setFitToWidth(true);
		this.sp.setMaxHeight(200);
		this.sp.setMinWidth(180);
	}

	// Recherche les plus petits ecarts en x et en y puis ajuste la distance
	// entre les rooms
	public void ppe() {
		this.roomList.forEach(room1 -> {
			this.roomList.forEach(room2 -> {
				if (room1.getX() != room2.getX())
					this.ppe_x = Math.min(this.ppe_x, Math.abs(room1.getX() - room2.getX()));
				if (room1.getY() != room2.getY())
					this.ppe_y = Math.min(this.ppe_y, Math.abs(room1.getY() - room2.getY()));
			});
		});
		roomList.forEach(room -> {
			if (this.ppe_x < 3)
				room.getRectangle().setX(room.getX() * (100 - (this.ppe_x * 30)));
			if (this.ppe_y < 3)
				room.getRectangle().setY(room.getY() * (100 - (this.ppe_y * 30)));
		});
	}

	// Affiche les pipes connectant les rooms et ajoute les boutons
	// correspondants
	public void displayPipes() {
		this.pipeList.forEach(pipe -> {
			pipe.display();
			this.map.getChildren().add(pipe.getLink());
			this.pipes.getChildren().add(pipe.getButton());
		});
	}

	// Affiche les rooms
	public void displayRooms() {
		this.roomList.forEach(room -> {
			this.map.getChildren().add(room.getRectangle());
		});
	}

	public Rectangle getBackground() {
		return background;
	}

	public void setBackground(Rectangle background) {
		this.background = background;
	}

	public LinkedList<Pipe> getPipeList() {
		return pipeList;
	}

	public LinkedList<Room> getRoomList() {
		return roomList;
	}

	public Room getRoom(String name) {
		for (Room room : this.roomList)
			if (room.getName().equals(name))
				return room;
		return null;
	}

	public Room getStart() {
		for (Room room : this.roomList)
			if (room.getRole() == 1)
				return room;
		return null;
	}

	public LinkedList<Move> getMoveList() {
		return moveList;
	}

	public Group getRoot() {
		return root;
	}

	public Group getMap_container() {
		return map_container;
	}

	public Group getMap() {
		return map;
	}

	public Scene getScene() {
		return scene;
	}

	public Stage getWindow() {
		return window;
	}

	public void setWindow(Stage window) {
		this.window = window;
	}

	public VBox getPipes() {
		return pipes;
	}

	public ScrollPane getSp() {
		return sp;
	}

	public int getX_min() {
		return x_min;
	}

	public int getY_min() {
		return y_min;
	}

	public int getX_max() {
		return x_max;
	}

	public int getY_max() {
		return y_max;
	}

	public int getAnt() {
		return ant;
	}
}
