
public class Anchor {
	
	private int x, y;
	private int size;
	
	public Anchor(int x, int y, int size)
	{
		this.setX(x);
		this.setY(y);
		this.setSize(size);
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
	
	public int getSize() {
		return this.size;
	}
	
	public void setSize(int size) {
		this.size = size;
	}
	
}
