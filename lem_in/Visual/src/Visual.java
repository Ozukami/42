
import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Scanner;
import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Orientation;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ScrollBar;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.TextArea;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;
import javafx.scene.input.ScrollEvent;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.BorderStroke;
import javafx.scene.layout.BorderWidths;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.Region;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.shape.CubicCurve;
import javafx.scene.shape.Line;
import javafx.stage.Stage;

public class Visual extends Application {

	static double x, y;
	int id = -1;
	int ppe_x = 3;
	int ppe_y = 3;
	LinkedList<Room> roomList = new LinkedList<Room>();

	public static void main(String[] args) {
		Application.launch(Visual.class, args);
	}

	@Override
	public void start(Stage primaryStage) {
		int	i = 0;
		int ant = 0;
		int role = 0;
		int x_min = 0;
		int x_max = 0;
		int y_min = 0;
		int y_max = 0;
		String line;
		String split[];
		LinkedList<Pipe> pipeList = new LinkedList<Pipe>();
        try {
			Scanner sc = new Scanner (new File (System.getProperty("user.dir") + "/src/test2"));
			while (sc.hasNext())
			{
				if (i++ == 0)
					ant = sc.nextInt();
				else
				{
					line = sc.nextLine();
					if (line.equals("##start") || line.equals("##end"))
					{
						role = (line.equals("##start")) ? 1 : 2;
						line = sc.nextLine();
					}
					if (!(line.startsWith("#")) && line.contains(" "))
					{
						split = line.split(" ");
						int scale_x = 40;
						int scale_y = 40;
						roomList.add(new Room(split[0], Integer.parseInt(split[1]), Integer.parseInt(split[2]), scale_x, scale_y, role));
						x_min = Math.min(x_min, Integer.parseInt(split[1]));
						x_max = Math.max(x_max, Integer.parseInt(split[1]));
						y_min = Math.min(y_min, Integer.parseInt(split[2]));
						y_max = Math.max(y_max, Integer.parseInt(split[2]));
					}
					else if (!(line.startsWith("#")) && line.contains("-"))
					{
						split = line.split("-");
						Pipe pipe = new Pipe(split[0], split[1]);
						for (Room room:roomList) {
							if (room.getName().equals(split[0]))
								pipe.setId1(room.getId());
							if (room.getName().equals(split[1]))
								pipe.setId2(room.getId());
						}
						pipeList.add(pipe);
					}
					role = 0;
				}
			}
			sc.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		primaryStage.setTitle("Lem-in");
		primaryStage.setMinWidth(720);
		primaryStage.setMinHeight(720);
		Group root = new Group();
		Group map_container = new Group();
		Group map = new Group();
		Scene scene = new Scene(root, ((x_max >= y_max) ? 1080 : 720), ((y_max >= x_max) ? 1080 : 720), Color.GREY);
		root.getChildren().add(map_container);
		Rectangle background = new Rectangle(1080, 1080, Color.GREY);
		map_container.getChildren().add(background);
		map_container.getChildren().add(map);
		String cssLayout = "-fx-border-color: darkgrey;\n" + "-fx-border-insets: 5;\n" +
                "-fx-border-width: 3;\n" + "-fx-background-color: darkgrey;\n";
		VBox pipes = new VBox(5);
		ScrollPane sp = new ScrollPane(pipes);
		sp.setLayoutX(20);
		sp.setLayoutY(20);
		sp.setHbarPolicy(ScrollPane.ScrollBarPolicy.NEVER);
		root.getChildren().add(sp);
		pipes.setStyle(cssLayout);
		sp.setStyle(cssLayout);
		sp.setFitToWidth(true);
		pipes.setLayoutX(20);
		pipes.setLayoutY(20);
		pipes.setMaxHeight(200);
		pipes.setMinHeight(100);
		pipes.setMinWidth(146);
		sp.setMaxHeight(200);
		sp.setMinWidth(180);
		map.requestFocus();
		System.out.printf("\nAnt = %d\n", ant);
		roomList.forEach(elem -> {
			roomList.forEach(elem2 -> {
				if (elem.getX() != elem2.getX())
					ppe_x = Math.min(ppe_x, Math.abs(elem.getX() - elem2.getX()));
				if (elem.getY() != elem2.getY())
					ppe_y = Math.min(ppe_y, Math.abs(elem.getY() - elem2.getY()));
			});
		});
		roomList.forEach(elem -> {
			if (ppe_x < 3)
				elem.getRectangle().setX(elem.getX() * (100 - (ppe_x * 30)));
			if (ppe_y < 3)
				elem.getRectangle().setY(elem.getY() * (100 - (ppe_y * 30)));
			elem.setX_mid((int)(elem.getRectangle().getX() + (elem.getRectangle().getWidth() / 2)));
			elem.setY_mid((int)(elem.getRectangle().getY() + (elem.getRectangle().getHeight() / 2)));
		});
		pipeList.forEach(pipe -> {
			int scale_x = roomList.get(pipe.getId1()).getScale_x();
			int scale_y = roomList.get(pipe.getId1()).getScale_y();
			pipe.setLine(new Line(roomList.get(pipe.getId1()).getX_mid(), roomList.get(pipe.getId1()).getY_mid(),
					roomList.get(pipe.getId2()).getX_mid(), roomList.get(pipe.getId2()).getY_mid()));
			pipe.getLine().setStrokeWidth(10);
			map.getChildren().add(pipe.getLine());
			pipes.getChildren().add(new Button(pipe.getName1() + "-" + pipe.getName2()));
		});
		roomList.forEach(room -> {
			map.getChildren().add(room.getRectangle());
		});
		scene.setOnKeyPressed(new EventHandler<KeyEvent>() {
			@Override
			public void handle(KeyEvent event) {
				if (event.getCode() == KeyCode.ESCAPE)
					System.exit(0);
				else
					System.out.println(event.getCharacter());
			}
		});
		scene.setOnMousePressed(new EventHandler<MouseEvent>() {
			@Override
			public void handle(MouseEvent event) {
				x = event.getSceneX();
				y = event.getSceneY();
			}
		});
		scene.setOnMouseDragged(new EventHandler<MouseEvent>() {
			@Override
			public void handle(MouseEvent event) {
				map.setLayoutX(map.getLayoutX() + event.getSceneX() - x);
				map.setLayoutY(map.getLayoutY() + event.getSceneY() - y);
				x = event.getSceneX();
				y = event.getSceneY();
			}
		});
		map_container.setOnScroll(new EventHandler<ScrollEvent>() {
			@Override
			public void handle(ScrollEvent event) {
					if (event.getDeltaY() > 0)
					{
						map.setScaleX(map.getScaleX() * 1.2);
						map.setScaleY(map.getScaleY() * 1.2);
					}
					if (event.getDeltaY() < 0)
					{
						map.setScaleX(map.getScaleX() * 0.8);
						map.setScaleY(map.getScaleY() * 0.8);
					}
			}
		});
		primaryStage.setScene(scene);
		primaryStage.show();
	}
}