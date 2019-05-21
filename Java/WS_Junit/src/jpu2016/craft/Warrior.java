package jpu2016.craft;

import jpu2016.hero.IHero;
import jpu2016.hit.Hit;
import jpu2016.hit.TypeHit;

public class Warrior extends Classe {

	public Warrior(final IHero hero) {
		super(hero);
	}

	@Override
	public Hit getHit() {
		Hit hit = new Hit(5, 0, TypeHit.NORMAL);
		Hit hitModifie = race.modifieLeCoup(hit);
		return hitModifie;
	}

}
