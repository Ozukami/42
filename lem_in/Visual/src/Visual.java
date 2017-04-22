
import java.util.LinkedList;
import java.util.Scanner;
import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;

public class Visual extends Application {

	static double x, y;
	LinkedList<Room> roomList = new LinkedList<Room>();

	public static void main(String[] args) {
		Application.launch(Visual.class, args);
	}

	@Override
	public void start(Stage primaryStage) {
		int	i = 0;
		int ant = 0;
		int role = 0;
		int x_max = 0;
		int y_max = 0;
		String line;
		String split[];
		LinkedList<Pipe> pipeList = new LinkedList<Pipe>();
		Scanner sc = new Scanner(System.in);
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
					roomList.add(new Room(split[0], Integer.parseInt(split[1]), Integer.parseInt(split[2]), role));
					x_max = Math.max(x_max, Integer.parseInt(split[1]));
					y_max = Math.max(y_max, Integer.parseInt(split[2]));
				}
				else if (!(line.startsWith("#")) && line.contains("-"))
				{
					split = line.split("-");
					pipeList.add(new Pipe(split[0], split[1]));
				}
				role = 0;
			}
		}
		sc.close();
		primaryStage.setTitle("Title");
		Group root = new Group();
		Scene scene = new Scene(root, ((x_max >= y_max) ? 1280 : 720), ((y_max >= x_max) ? 1280 : 720), Color.GREY);
		System.out.printf("\nAnt = %d\n", ant);
		roomList.forEach(elem -> {
			//    		System.out.printf("%d %s %d %d %s\n", elem.getId(), elem.getName(), elem.getX(), elem.getY(),
			//    				((elem.getRole() == 1) ? "Start" : (elem.getRole() == 2) ? "End" : "None"));
			elem.getRectangle().setX(elem.getX() * 50);
			elem.getRectangle().setY(elem.getY() * 50);
			elem.getRectangle().setHeight(50);
			elem.getRectangle().setWidth(75);
			elem.getRectangle().setFill(((elem.getRole() == 1) ? Color.RED : (elem.getRole() == 2) ? Color.GREEN : Color.BLUE));
			elem.getRectangle().setStroke(Color.rgb(200, 200, 200));
			elem.getRectangle().setStrokeWidth(5);
			elem.getRectangle().setArcHeight(30);
			elem.getRectangle().setArcWidth(30);
			root.getChildren().add(elem.getRectangle());
		});
		pipeList.forEach(elem -> {
			System.out.printf("%s-%s\n", elem.getName1(), elem.getName2());
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
		            	roomList.forEach(elem -> {
							double deltaX = event.getSceneX() - x ;
							double deltaY = event.getSceneY() - y ;
		            		elem.getRectangle().setX(elem.getRectangle().getX() + deltaX);
		            		elem.getRectangle().setY(elem.getRectangle().getY() + deltaY);
		            	});
		            	x = event.getSceneX();
		            	y = event.getSceneY();
		            }
				});
		primaryStage.setScene(scene);
		primaryStage.show();
	}
}