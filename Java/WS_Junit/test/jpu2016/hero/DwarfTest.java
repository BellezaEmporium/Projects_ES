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

public class DwarfTest {
	@Test
	public void testArcherDwarf() {
		Classe c = new Archer(new Dwarf());
		Hit hit = c.getHit();
		assertEquals(4, hit.getStrength());
		assertEquals(6, hit.getRange());
		assertEquals(TypeHit.NORMAL, hit.getTypeHit());
	}

	@Test
	public void testAssassinDwarf() {
		Classe c = new Assassin(new Dwarf());
		Hit hit = c.getHit();
		assertEquals(4, hit.getStrength());
		assertEquals(0, hit.getRange());
		assertEquals(TypeHit.POISON, hit.getTypeHit());
	}

	@Test
	public void testWizardDwarf() {
		Classe c = new Wizard(new Dwarf());
		Hit hit = c.getHit();
		assertEquals(6, hit.getStrength());
		assertEquals(3, hit.getRange());
		assertEquals(TypeHit.MAGIC, hit.getTypeHit());
	}

	@Test
	public void testWarriorDwarf() {
		Classe c = new Warrior(new Dwarf());
		Hit hit = c.getHit();
		assertEquals(10, hit.getStrength());
		assertEquals(0, hit.getRange());
		assertEquals(TypeHit.NORMAL, hit.getTypeHit());
	}
}
