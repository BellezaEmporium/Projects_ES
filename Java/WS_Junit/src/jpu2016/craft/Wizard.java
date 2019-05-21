package jpu2016.craft;

import jpu2016.hero.IHero;
import jpu2016.hit.Hit;
import jpu2016.hit.TypeHit;

public class Wizard extends Classe {

	public Wizard(final IHero hero) {
		super(hero);
	}

	@Override
	public Hit getHit() {
		Hit hit = new Hit(3, 5, TypeHit.MAGIC);
		Hit hitModifie = race.modifieLeCoup(hit);
		return hitModifie;
	}

}
