package jpu2016.craft;

import jpu2016.hero.IHero;
import jpu2016.hit.Hit;

public abstract class Classe {
	protected final IHero race;

	public Classe(final IHero race) {
		this.race = race;
	}

	public abstract Hit getHit();
}
