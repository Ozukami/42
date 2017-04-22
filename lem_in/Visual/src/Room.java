
public class Room {

	private String	name;
	private static int count = 0;
	private int	id;
	private int	role;
	private int x;
	private int y;
	
	public Room()
	{
		this.setName("A Room has no name");
		this.setX(0);
		this.setY(0);
		this.setRole(0);
	}
	
	public Room(String name)
	{
		this.setName(name);
		this.setX(0);
		this.setY(0);
		this.setRole(0);
	}
	
	public Room(String name, int x, int y)
	{
		this.setName(name);
		this.setX(x);
		this.setY(y);
		this.setRole(0);
		this.id = count++;
	}
	
	public Room(String name, int x, int y, int role)
	{
		this.setName(name);;
		this.setX(x);
		this.setY(y);
		this.setRole(role);
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
}
