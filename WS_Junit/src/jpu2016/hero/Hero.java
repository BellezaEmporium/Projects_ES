package jpu2016.hero;

import jpu2016.craft.Classe;
import jpu2016.hit.Hit;
import jpu2016.hit.TypeHit;

public abstract class Hero implements IHero {
	private Classe classe;
	int modificateurStrenght;
	int modificateurRange;
	TypeHit modificateurTypeHit;

	public Hero(int modificateurStrenght, int modificateurRange, TypeHit modificateurTypeHit) {
		this.modificateurStrenght = modificateurStrenght;
		this.modificateurRange = modificateurRange;
		this.modificateurTypeHit = modificateurTypeHit;
	}

	@Override
	public Hit modifieLeCoup(Hit hit) {
		int strength = hit.getStrength() + modificateurStrenght;
		if (strength < 0)
			strength = 0;
		strength = modifieStrength(hit.getStrength(), strength);

		int range = hit.getRange() + modificateurRange;
		if (range < 0)
			range = 0;
		range = modifieRange(hit.getRange(), range);
		TypeHit type = hit.getTypeHit();
		if (modificateurTypeHit != null)
			type = modificateurTypeHit;

		return new Hit(strength, range, type);
	}

	protected int modifieRange(int rangeAvantModificateur, int rangeApres) {
		return rangeApres;
	}

	protected int modifieStrength(int strengthAvantModificateur, int strengthApres) {
		return strengthApres;
	}

	public void setCraft(final Classe craft) {
		this.classe = craft;
	}
}
