
import javafx.scene.shape.Line;

public class Pipe {
	
	private String name1, name2;
	private int id1, id2;
	private Line line;

	public Pipe(String name1, String name2) {
		this.setName1(name1);
		this.setName2(name2);
		this.setId1(-1);
		this.setId2(-1);
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
	
	public int getId1() {
		return id1;
	}

	public void setId1(int id1) {
		this.id1 = id1;
	}

	public int getId2() {
		return id2;
	}

	public void setId2(int id2) {
		this.id2 = id2;
	}

	public Line getLine() {
		return line;
	}

	public void setLine(Line line) {
		this.line = line;
	}
}
