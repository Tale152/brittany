package utility;

public class Pair<X,Y> {
	
	private final X x;
	private final Y y;	
	
	public Pair(final X x, final Y y) {
		this.x = x;
		this.y = y;
	}

	public X getX() {
		return x;
	}

	public Y getY() {
		return y;
	}

	@Override
	public String toString() {
		return "Pair [x=" + x + ", y=" + y + "]";
	}
	
}
