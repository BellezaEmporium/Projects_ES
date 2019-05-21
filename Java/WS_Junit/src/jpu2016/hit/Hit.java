package jpu2016.hit;

public class Hit {
	private final int strength;
	private final int range;
	private final TypeHit typeHit;

	public Hit(final int strength, final int range, final TypeHit typeHit) {
		if ((strength < 0) || (strength > 100)) {
			throw new IllegalArgumentException("Strength out of range");
		}
		this.strength = strength;

		if ((range < 0) || (range > 10)) {
			throw new IllegalArgumentException("Range out of range");
		}
		this.range = range;
		this.typeHit = typeHit;
	}

	public int getStrength() {
		return this.strength;
	}

	public int getRange() {
		return this.range;
	}

	public TypeHit getTypeHit() {
		return this.typeHit;
	}

}
