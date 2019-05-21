package jpu2016.hero;

public class Elf extends Hero {
	public Elf() {
		super(-1, 2, null);
	}

	@Override
	protected int modifieRange(int rangeAvantModificateur, int rangeApres) {
		if (rangeAvantModificateur == 0)
			return 0;
		else if (rangeAvantModificateur > 0)
			return rangeApres;
		else
			throw new IllegalArgumentException(
					"Impossible d'avoir une range avant modif < 0 (" + rangeAvantModificateur + ")");
	}
}
