
public class Move {

	private int turn;
	private int ant_id;
	private Room room;

	public Move(int turn, int ant_id, Room room) {
		this.turn = turn;
		this.ant_id = ant_id;
		this.room = room;
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

	public Room getRoom() {
		return room;
	}
}
