
public class Move {

	private int turn;
	private int ant_id;
	private String room_name;
	
	public Move(int turn, int ant_id, String room_name) {
		this.turn = turn;
		this.ant_id = ant_id;
		this.room_name = room_name;
	}
	
	public int getTurn() {
		return turn;
	}
	public int getAnt_id() {
		return ant_id;
	}
	public String getRoom_name() {
		return room_name;
	}
}
