
import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;
import javafx.scene.input.ScrollEvent;
import javafx.stage.Stage;

public class Visual extends Application {

	static double x, y;
	int ppe_x = 3, ppe_y = 3;

	public static void main(String[] args) {
		Application.launch(Visual.class, args);
	}

	@Override
	public void start(Stage primaryStage) {
		Env env = new Env();
		System.out.printf("\nAnt = %d\n", env.getAnt());
		
		env.ppe();
		env.displayPipes();
		env.displayRooms();
		
		// Key handlers
		keyHandlers(env.getScene());
		
		// Mouse handlers
		env.getScene().setOnMousePressed(new EventHandler<MouseEvent>() {
			@Override
			public void handle(MouseEvent event) {
				x = event.getSceneX();
				y = event.getSceneY();
			}
		});
		env.getScene().setOnMouseDragged(new EventHandler<MouseEvent>() {
			@Override
			public void handle(MouseEvent event) {
				env.getMap().setLayoutX(env.getMap().getLayoutX() + event.getSceneX() - x);
				env.getMap().setLayoutY(env.getMap().getLayoutY() + event.getSceneY() - y);
				x = event.getSceneX();
				y = event.getSceneY();
			}
		});
		env.getMap_container().setOnScroll(new EventHandler<ScrollEvent>() {
			@Override
			public void handle(ScrollEvent event) {
					if (event.getDeltaY() > 0)
					{
						env.getMap().setScaleX(env.getMap().getScaleX() * 1.2);
						env.getMap().setScaleY(env.getMap().getScaleY() * 1.2);
					}
					if (event.getDeltaY() < 0)
					{
						env.getMap().setScaleX(env.getMap().getScaleX() * 0.8);
						env.getMap().setScaleY(env.getMap().getScaleY() * 0.8);
					}
			}
		});
		primaryStage.setTitle("Lem-in");
		primaryStage.setMinWidth((env.getX_max() >= env.getY_max()) ? 1080 : 720);
		primaryStage.setMinHeight((env.getY_max() >= env.getX_max()) ? 1080 : 720);
		primaryStage.setScene(env.getScene());
		primaryStage.show();
	}
	
	public void keyHandlers(Scene scene) {
		scene.setOnKeyPressed(new EventHandler<KeyEvent>() {
			@Override
			public void handle(KeyEvent event) {
				if (event.getCode() == KeyCode.ESCAPE)
				{
					System.out.println("ESCAPE KeyCode received, exiting...");
					System.exit(0);
				}
				else
					System.out.println(event.getCharacter());
			}
		});
	}
	
	public void mouseHandlers(Scene scene) {
		// TODO
	}
}