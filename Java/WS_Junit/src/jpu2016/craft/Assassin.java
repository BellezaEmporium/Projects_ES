package jpu2016.craft;

import jpu2016.hero.IHero;
import jpu2016.hit.Hit;
import jpu2016.hit.TypeHit;

public class Assassin extends Classe {

	public Assassin(final IHero hero) {
		super(hero);
	}

	@Override
	public Hit getHit() {
		Hit hit = new Hit(2, 0, TypeHit.POISON);
		Hit hitModifie = race.modifieLeCoup(hit);
		return hitModifie;
	}

}
