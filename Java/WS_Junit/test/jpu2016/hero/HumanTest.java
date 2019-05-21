package jpu2016.hero;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

import jpu2016.craft.Archer;
import jpu2016.craft.Assassin;
import jpu2016.craft.Classe;
import jpu2016.craft.Warrior;
import jpu2016.craft.Wizard;
import jpu2016.hit.Hit;
import jpu2016.hit.TypeHit;

public class HumanTest {

	@Test
	public void testArcherHumain() {
		Classe c = new Archer(new Human());
		Hit hit = c.getHit();
		assertEquals(2, hit.getStrength());
		assertEquals(8, hit.getRange());
		assertEquals(TypeHit.NORMAL, hit.getTypeHit());
	}

	@Test
	public void testWizardHumain() {
		Classe c = new Wizard(new Human());
		Hit hit = c.getHit();
		assertEquals(3, hit.getStrength());
		assertEquals(5, hit.getRange());
		assertEquals(TypeHit.MAGIC, hit.getTypeHit());
	}

	@Test
	public void testWarriorHumain() {
		Classe c = new Warrior(new Human());
		Hit hit = c.getHit();
		assertEquals(5, hit.getStrength());
		assertEquals(0, hit.getRange());
		assertEquals(TypeHit.NORMAL, hit.getTypeHit());
	}

	@Test
	public void testAssassinHumain() {
		Classe c = new Assassin(new Human());
		Hit hit = c.getHit();
		assertEquals(2, hit.getStrength());
		assertEquals(0, hit.getRange());
		assertEquals(TypeHit.POISON, hit.getTypeHit());
	}

}
