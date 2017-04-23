
import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Scanner;
import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;
import javafx.scene.input.ScrollEvent;
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
		Group root = new Group();
		Scene scene = new Scene(root, ((x_max >= y_max) ? 1080 : 720), ((y_max >= x_max) ? 1080 : 720), Color.GREY);
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
			root.getChildren().add(pipe.getLine());
		});
		roomList.forEach(elem -> {
			root.getChildren().add(elem.getRectangle());
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
				root.setLayoutX(root.getLayoutX() + event.getSceneX() - x);
				root.setLayoutY(root.getLayoutY() + event.getSceneY() - y);
				x = event.getSceneX();
				y = event.getSceneY();
			}
		});
		scene.setOnScroll(new EventHandler<ScrollEvent>() {
			@Override
			public void handle(ScrollEvent event) {
				// TODO Auto-generated method stub
				if (event.getDeltaY() > 0)
				{
					root.setScaleX(root.getScaleX() * 1.2);
					root.setScaleY(root.getScaleY() * 1.2);
				}
				if (event.getDeltaY() < 0)
				{
					root.setScaleX(root.getScaleX() * 0.8);
					root.setScaleY(root.getScaleY() * 0.8);
				}
			}
		});
		primaryStage.setScene(scene);
		primaryStage.show();
	}
}