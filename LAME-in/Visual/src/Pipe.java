
import javafx.animation.RotateTransition;
import javafx.animation.ScaleTransition;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.ToggleButton;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.paint.Paint;
import javafx.scene.shape.Line;
import javafx.scene.shape.StrokeLineCap;
import javafx.util.Duration;

public class Pipe {

	private Room room1, room2;
	private String name1, name2;
	private StackPane link;
	private Line outer;
	private Line inner;
	private ToggleButton button;
	private RotateTransition rT;
	private ScaleTransition sT;

	public Pipe(Room room1, Room room2) {
		this.room1 = room1;
		this.room2 = room2;
		this.setName1(room1.getName());
		this.setName2(room2.getName());
		this.setLink(new StackPane());
		this.outer = new Line();
		this.inner = new Line();
		this.getLink().getChildren().addAll(outer, inner);
		this.setButton(new ToggleButton(name1 + "-" + name2));
		this.rT = new RotateTransition(Duration.seconds(0.5), this.link);
		this.sT = new ScaleTransition(Duration.seconds(0.5), this.button);
		this.button.setOnAction(new EventHandler<ActionEvent>() {

			@Override
			public void handle(ActionEvent event) {
				if (button.isSelected()) {
					rT.setByAngle(180);
					sT.setByX(0.3);
					sT.setByY(0.3);
					sT.setAutoReverse(true);
					sT.setCycleCount(2);
					rT.play();
					sT.play();
					getOuter().setStroke(Color.DARKORANGE);
					getLink().toFront();
				} else {
					rT.setByAngle(-180);
					sT.setByX(-0.3);
					sT.setByY(-0.3);
					sT.setAutoReverse(true);
					sT.setCycleCount(2);
					rT.play();
					sT.play();
					getOuter().setStroke(Color.BLACK);
					getLink().toBack();
				}
			}
		});
	}

	public void display() {
		this.getLink().setLayoutX(Math.min(this.getRoom1().getX_mid() - 5, this.getRoom2().getX_mid() - 5));
		this.getLink().setLayoutY(Math.min(this.getRoom1().getY_mid() - 5, this.getRoom2().getY_mid() - 5));

		this.initLine(this.getOuter(), Color.BLACK, 10);
		this.initLine(this.getInner(), Color.RED, 4);
	}

	public void initLine(Line line, Paint color, int strokeWidth) {
		line.setStroke(color);
		line.setStartX(this.getRoom1().getX_mid());
		line.setStartY(this.getRoom1().getY_mid());
		line.setEndX(this.getRoom2().getX_mid());
		line.setEndY(this.getRoom2().getY_mid());
		line.setStrokeLineCap(StrokeLineCap.ROUND);
		line.setStrokeWidth(strokeWidth);
		line.setSmooth(true);
	}

	public Room getRoom1() {
		return room1;
	}

	public Room getRoom2() {
		return room2;
	}

	public String getName1() {
		return name1;
	}

	public void setName1(String name1) {
		this.name1 = name1;
	}

	public String getName2() {
		return name2;
	}

	public void setName2(String name2) {
		this.name2 = name2;
	}

	public StackPane getLink() {
		return link;
	}

	public void setLink(StackPane link) {
		this.link = link;
	}

	public Line getInner() {
		return inner;
	}

	public Line getOuter() {
		return outer;
	}

	public ToggleButton getButton() {
		return button;
	}

	public void setButton(ToggleButton button) {
		this.button = button;
	}
}
