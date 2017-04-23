import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class Room {

	private static int count = 0;
	private String	name;
	private int	id,	role, x, y; // x,y = coordonnees d'ancrage
	private Rectangle rectangle;
	private Anchor northL, northR, east, west, southL, southR;
	private int x_mid, y_mid;
	private int scale_x, scale_y;

	public Room()
	{
		this.setName("A Room has no name");
		this.setX(0);
		this.setY(0);
		this.setRole(0);
		this.id = count++;
		this.setRectangle(new Rectangle());
	}
	
	public Room(String name, int x, int y, int scale_x, int scale_y, int role)
	{
		this.setName(name);;
		this.setX(x);
		this.setY(y);
		this.setRole(role);
		this.id = count++;
		this.setRectangle(x * scale_x, y * scale_y, 50, 70);
		this.rectangle.setX(x * scale_x);
		this.rectangle.setY(y * scale_y);
		this.setScale_x(scale_x);
		this.setScale_y(scale_y);
		this.setX_mid(x + ((int)this.getRectangle().getHeight() / 2));
		this.setY_mid(y + ((int)this.getRectangle().getWidth() / 2));
	}
	
	public void setRectangle(int x, int y, int height, int width) {
		this.rectangle = new Rectangle();
		this.rectangle.setX(x);
		this.rectangle.setY(y);
		this.rectangle.setHeight(height);
		this.rectangle.setWidth(width);
		this.rectangle.setFill(((this.getRole() == 1) ? Color.RED : (this.getRole() == 2) ? Color.GREEN : Color.BLUE));
		this.rectangle.setStroke(Color.rgb(200, 200, 200));
		this.rectangle.setStrokeWidth(5);
		this.rectangle.setArcHeight(30);
		this.rectangle.setArcWidth(30);
	}
	
	public int getX_mid() {
		return x_mid;
	}

	public void setX_mid(int x_mid) {
		this.x_mid = x_mid;
	}

	public int getY_mid() {
		return y_mid;
	}

	public void setY_mid(int y_mid) {
		this.y_mid = y_mid;
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
	
	public int getScale_x() {
		return scale_x;
	}

	public void setScale_x(int scale_x) {
		this.scale_x = scale_x;
	}

	public int getScale_y() {
		return scale_y;
	}

	public void setScale_y(int scale_y) {
		this.scale_y = scale_y;
	}
}
