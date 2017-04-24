
import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Scanner;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ScrollPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;
import javafx.scene.shape.Rectangle;

public class Env {

	private LinkedList<Room> roomList;
	private LinkedList<Pipe> pipeList;
	private Scene scene;
	private Group root;
	private Group map_container;
	private Group map;
	private Rectangle background;
	private VBox pipes;
	private ScrollPane sp;
	private int x_min = 0, y_min = 0;
	private int x_max = 0, y_max = 0;
	private int ant = 0;
	private int ppe_x = 3, ppe_y = 3;
	
	public Env() {
		roomList = new LinkedList<Room>();
		pipeList = new LinkedList<Pipe>();
		this.getData();
		
		scene = new Scene(root = new Group(), ((x_max >= y_max) ? 1080 : 720), ((y_max >= x_max) ? 1080 : 720), Color.GREY);
		map_container = new Group();
		map = new Group();
		background = new Rectangle(1080, 1080, Color.GREY);
		
		this.initPipes();
		this.initSP();
		
		root.getChildren().addAll(map_container, sp);
		map_container.getChildren().addAll(background, map);
		
		map.requestFocus();
	}
	
	private void getData() {
		String line;
		String split[];
		int role;
		
        try {
			Scanner sc = new Scanner (new File (System.getProperty("user.dir") + "/src/test2"));
			this.ant = sc.nextInt();
			while (sc.hasNext())
			{
				line = sc.nextLine();
				if (line.startsWith("L"))
					break ;
				role = 0;
				while (line.startsWith("#"))
				{
					role = (line.equals("##start")) ? 1 : ((line.equals("##end")) ? 2 : 0);
					line = sc.nextLine();
				}
				if (line.contains(" "))
				{
					split = line.split(" ");
					roomList.add(new Room(split[0], Integer.parseInt(split[1]), Integer.parseInt(split[2]), 40, 40, role));
					x_min = Math.min(x_min, Integer.parseInt(split[1])); y_min = Math.min(y_min, Integer.parseInt(split[2]));
					x_max = Math.max(x_max, Integer.parseInt(split[1])); y_max = Math.max(y_max, Integer.parseInt(split[2]));
				}
				else if (line.contains("-"))
				{
					split = line.split("-");
					Pipe pipe = new Pipe(split[0], split[1]);
					for (Room room:roomList)
					{
						if (room.getName().equals(split[0]))
							pipe.setId1(room.getId());
						if (room.getName().equals(split[1]))
							pipe.setId2(room.getId());
					}
					pipeList.add(pipe);
				}
			}
			sc.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	private void initPipes() {
		String cssLayout = "-fx-border-color: darkgrey;" + "\n-fx-border-insets: 5;\n" +
                "-fx-border-width: 3;\n" + "-fx-background-color: darkgrey;\n";
		pipes = new VBox(5);
		pipes.setStyle(cssLayout);
		pipes.setLayoutX(20);
		pipes.setLayoutY(20);
		pipes.setMinHeight(100);
		pipes.setMinWidth(146);
	}
	
	private void initSP() {
		String cssLayout = "-fx-border-color: darkgrey;" + "\n-fx-border-insets: 5;\n" +
                "-fx-border-width: 3;\n" + "-fx-background-color: darkgrey;\n";
		sp = new ScrollPane(pipes);
		sp.setLayoutX(20);
		sp.setLayoutY(20);
		sp.setHbarPolicy(ScrollPane.ScrollBarPolicy.NEVER);
		sp.setStyle(cssLayout);
		sp.setFitToWidth(true);
		sp.setMaxHeight(200);
		sp.setMinWidth(180);
	}

	// Recherche les plus petits ecarts en x et en y puis ajuste la distance entre les rooms
	public void ppe() {
		roomList.forEach(elem -> {
			roomList.forEach(elem2 -> {
				if (elem.getX() != elem2.getX())
					ppe_x = Math.min(ppe_x, Math.abs(elem.getX() - elem2.getX()));
				if (elem.getY() != elem2.getY())
					ppe_y = Math.min(ppe_y, Math.abs(elem.getY() - elem2.getY()));
			});
		});
		roomList.forEach(room -> {
			if (ppe_x < 3)
				room.getRectangle().setX(room.getX() * (100 - (ppe_x * 30)));
			if (ppe_y < 3)
				room.getRectangle().setY(room.getY() * (100 - (ppe_y * 30)));
		});
	}

	// Affiche les pipes connectant les rooms et ajoute les boutons correspondants
	public void displayPipes() {
		pipeList.forEach(pipe -> {
			pipe.setLine(new Line(roomList.get(pipe.getId1()).getX_mid(), roomList.get(pipe.getId1()).getY_mid(),
					roomList.get(pipe.getId2()).getX_mid(), roomList.get(pipe.getId2()).getY_mid()));
			pipe.getLine().setStrokeWidth(10);
			map.getChildren().add(pipe.getLine());
			pipes.getChildren().add(new Button(pipe.getName1() + "-" + pipe.getName2()));
		});
	}

	// Affiche les rooms
	public void displayRooms() {
		roomList.forEach(room -> {
			map.getChildren().add(room.getRectangle());
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
