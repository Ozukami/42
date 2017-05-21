
import javafx.animation.Animation;
import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.geometry.Rectangle2D;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyCodeCombination;
import javafx.scene.input.KeyCombination;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;
import javafx.scene.input.ScrollEvent;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
import javafx.util.Duration;

public class Visual extends Application {

	static double x, y;
	int ppe_x = 3, ppe_y = 3;

	public static void main(String[] args) {
		Application.launch(Visual.class, args);
	}

	@Override
	public void start(Stage primaryStage) {
		Env env = new Env(primaryStage);

		env.ppe();
		env.displayPipes();
		env.displayRooms();

		keyHandlers(env);
		mouseHandlers(env);

		env.getWindow().setTitle("Lem-in");
		env.getWindow().setMinWidth((env.getX_max() >= env.getY_max()) ? 1080 : 720);
		env.getWindow().setMinHeight((env.getY_max() >= env.getX_max()) ? 1080 : 720);
		env.getWindow().setScene(env.getScene());
		env.getWindow()
				.setFullScreenExitKeyCombination(new KeyCodeCombination(KeyCode.ESCAPE, KeyCombination.CONTROL_DOWN));
		env.getWindow().setFullScreenExitHint("ESCAPE to exit Full Screen");
		env.getWindow().show();
	}

	public void keyHandlers(Env env) {
		env.getScene().setOnKeyPressed(new EventHandler<KeyEvent>() {
			@Override
			public void handle(KeyEvent event) {
				if (event.getCode() == KeyCode.ESCAPE)
					if (env.getWindow().isFullScreen())
						env.getWindow().setFullScreen(false);
					else
						System.exit(0);
				else if (event.getCode() == KeyCode.M && event.isControlDown())
					env.getWindow().setFullScreen(true);
				else
					System.out.println(event.getCharacter());
			}
		});
	}

	public void mouseHandlers(Env env) {
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
				if (event.getDeltaY() > 0) {
					env.getMap().setScaleX(env.getMap().getScaleX() * 1.2);
					env.getMap().setScaleY(env.getMap().getScaleY() * 1.2);
				}
				if (event.getDeltaY() < 0) {
					env.getMap().setScaleX(env.getMap().getScaleX() * 0.8);
					env.getMap().setScaleY(env.getMap().getScaleY() * 0.8);
				}
			}
		});
	}
}