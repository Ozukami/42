
import javafx.animation.RotateTransition;
import javafx.animation.ScaleTransition;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.ToggleButton;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;
import javafx.util.Duration;

public class Pipe {
	
	private String name1, name2;
	private Line link;
	private ToggleButton button;
	private RotateTransition rT;
	private ScaleTransition sT;

	public Pipe(String name1, String name2) {
		this.setName1(name1);
		this.setName2(name2);
		this.setLink(new Line());
		this.setButton(new ToggleButton(name1 + "-" + name2));
		this.rT = new RotateTransition(Duration.seconds(0.5), this.link);
		this.sT = new ScaleTransition(Duration.seconds(0.5), this.button);
		this.button.setOnAction(new EventHandler<ActionEvent>() {
			
			@Override
			public void handle(ActionEvent event) {
				if (button.isSelected())
				{
					rT.setByAngle(180);
					sT.setByX(0.3);
					sT.setByY(0.3);
					sT.setAutoReverse(true);
					sT.setCycleCount(2);
					rT.play();
					sT.play();
					getLink().setStroke(Color.DARKORANGE);
					getLink().toFront();
				}
				else
				{
					rT.setByAngle(-180);
					sT.setByX(-0.3);
					sT.setByY(-0.3);
					sT.setAutoReverse(true);
					sT.setCycleCount(2);
					rT.play();
					sT.play();
					getLink().setStroke(Color.BLACK);
					getLink().toBack();
				}
			}
		});
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

	public Line getLink() {
		return link;
	}

	public void setLink(Line link) {
		this.link = link;
	}

	public ToggleButton getButton() {
		return button;
	}

	public void setButton(ToggleButton button) {
		this.button = button;
	}
}
