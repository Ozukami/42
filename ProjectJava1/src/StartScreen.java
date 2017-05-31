
import javafx.scene.Group;
import javafx.scene.Node;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;

public class StartScreen extends Group {

	private BorderPane layout;
	private Label title;
	private Label creds;
	private VBox menu;
	private Button newGame;
	private Button continueGame;
	private Button exitGame;

	public StartScreen(Node Children) {
		super();
		this.title = new Label("GATE");
		this.creds = new Label("2017		©		Credit Ozuk & Q");
		this.newGame = new Button("New");
		this.continueGame = new Button("Continue...");
		this.exitGame = new Button("Exit");
		this.menu = new VBox(30, this.newGame, this.continueGame, this.exitGame);
		Pane left = new Pane();
		Pane right = new Pane();
		left.setMinWidth(350);
		right.setMinWidth(350);
		this.layout = new BorderPane(this.menu, this.title, right, this.creds, left);
		this.getChildren().add(layout);
	}
}