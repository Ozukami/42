
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Button;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;

public class Pipe {
	
	private String name1, name2;
	private Line link;
	private Button button;
	private int clicked;

	public Pipe(String name1, String name2) {
		this.setName1(name1);
		this.setName2(name2);
		this.setButton(new Button(name1 + "-" + name2));
		this.clicked = 0;
		this.button.setOnAction(new EventHandler<ActionEvent>() {
			
			@Override
			public void handle(ActionEvent event) {
				if (clicked == 0)
				{
					getLink().setStroke(Color.DARKORANGE);
					getLink().toFront();
					clicked = 1;
				}
				else
				{
					getLink().setStroke(Color.BLACK);
					getLink().toBack();
					clicked = 0;
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

	public Button getButton() {
		return button;
	}

	public void setButton(Button button) {
		this.button = button;
	}
}
