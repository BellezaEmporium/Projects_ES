package jpu2016.hero;

public class Dwarf extends Hero {
	public Dwarf() {
		super(0, -2, null);
	}

	@Override
	protected int modifieStrength(int strengthAvantModificateur, int strengthApres) {
		int forceDoublee = strengthAvantModificateur * 2;
		if (forceDoublee > 100)
			forceDoublee = 100;
		return forceDoublee;
	}
}
