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

public class ElfTest {

	@Test
	public void testArcherElfe() {
		Classe c = new Archer(new Elf());
		Hit hit = c.getHit();
		assertEquals(1, hit.getStrength());
		assertEquals(10, hit.getRange());
		assertEquals(TypeHit.NORMAL, hit.getTypeHit());
	}

	@Test
	public void testAssassinElfe() {
		Classe c = new Assassin(new Elf());
		Hit hit = c.getHit();
		assertEquals(1, hit.getStrength());
		assertEquals(0, hit.getRange());
		assertEquals(TypeHit.POISON, hit.getTypeHit());
	}

	@Test
	public void testWarriorElfe() {
		Classe c = new Warrior(new Elf());
		Hit hit = c.getHit();
		assertEquals(4, hit.getStrength());
		assertEquals(0, hit.getRange());
		assertEquals(TypeHit.NORMAL, hit.getTypeHit());
	}

	@Test
	public void testWizardElfe() {
		Classe c = new Wizard(new Elf());
		Hit hit = c.getHit();
		assertEquals(2, hit.getStrength());
		assertEquals(7, hit.getRange());
		assertEquals(TypeHit.MAGIC, hit.getTypeHit());
	}
}
