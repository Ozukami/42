import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class Room {

	private static int count = 0;
	private String	name;
	private int	id,	role, x, y;
	private Rectangle rectangle;
	private Anchor northL, northR, east, west, southL, southR;
	
	public Room()
	{
		this.setName("A Room has no name");
		this.setX(0);
		this.setY(0);
		this.setRole(0);
		this.id = count++;
		this.setRectangle(new Rectangle());
	}
	
	public Room(String name, int x, int y, int role)
	{
		this.setName(name);;
		this.setX(x);
		this.setY(y);
		this.setRole(role);
		this.id = count++;
		this.setRectangle(new Rectangle());
		this.rectangle.setX(x * 50);
		this.rectangle.setY(y * 50);
		this.rectangle.setHeight(50);
		this.rectangle.setWidth(75);
		this.rectangle.setFill(((role == 1) ? Color.RED : (role == 2) ? Color.GREEN : Color.BLUE));
		this.rectangle.setStroke(Color.rgb(200, 200, 200));
		this.rectangle.setStrokeWidth(5);
		this.rectangle.setArcHeight(30);
		this.rectangle.setArcWidth(30);
	}
	
	public String getName()
	{
		return (this.name);
	}
	
	public void setName(String name)
	{
		this.name = name;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public int getRole() {
		return role;
	}

	public void setRole(int role) {
		this.role = role;
	}

	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}

	public Rectangle getRectangle() {
		return rectangle;
	}

	public void setRectangle(Rectangle rectangle) {
		this.rectangle = rectangle;
	}
	
	public static int getCount() {
		return count;
	}

	public static void setCount(int count) {
		Room.count = count;
	}

	public Anchor getNorthL() {
		return northL;
	}

	public void setNorthL(Anchor northL) {
		this.northL = northL;
	}

	public Anchor getNorthR() {
		return northR;
	}

	public void setNorthR(Anchor northR) {
		this.northR = northR;
	}

	public Anchor getEast() {
		return east;
	}

	public void setEast(Anchor east) {
		this.east = east;
	}

	public Anchor getWest() {
		return west;
	}

	public void setWest(Anchor west) {
		this.west = west;
	}

	public Anchor getSouthL() {
		return southL;
	}

	public void setSouthL(Anchor southL) {
		this.southL = southL;
	}

	public Anchor getSouthR() {
		return southR;
	}

	public void setSouthR(Anchor southR) {
		this.southR = southR;
	}
}
