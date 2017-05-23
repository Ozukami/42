
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

public class PopUp extends Stage {

	private Text text;
	private Button button;
	private Scene scene;

	public PopUp(int ant_end, int nb_turn) {
		this.text = new Text(10, 10,
				String.format("Les %d fourmis ", ant_end) + String.format("sont arrivees en %d tours !", nb_turn));
		this.button = new Button("Exit");
		scene = new Scene(new Group(text, button));
		button.setLayoutX(150);
		button.setLayoutY(25);
		this.setWidth(350);
		this.setHeight(100);
		this.initStyle(StageStyle.UTILITY);
		this.setScene(scene);
		button.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent event) {
				System.exit(1);
			}
		});
		scene.setOnKeyPressed(new EventHandler<KeyEvent>() {
			@Override
			public void handle(KeyEvent event) {
				if (event.getCode() == KeyCode.ESCAPE) {
					System.exit(1);
				}
			}
		});
		this.show();
	}
}
