
public class Move {

	private int turn;
	private int ant_id;
	private Room fromRoom;
	private Room toRoom;

	public Move(int turn, int ant_id, Room toRoom, Room fromRoom) {
		this.turn = turn;
		this.ant_id = ant_id;
		this.toRoom = toRoom;
		this.fromRoom = fromRoom;
	}

	public int getTurn() {
		return turn;
	}

	public int getAnt_id() {
		return ant_id;
	}

	public Room getToRoom() {
		return toRoom;
	}

	public Room getFromRoom() {
		return fromRoom;
	}
}
