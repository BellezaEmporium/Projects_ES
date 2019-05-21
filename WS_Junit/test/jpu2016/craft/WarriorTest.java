package jpu2016.craft;

import org.junit.jupiter.api.BeforeEach;

import jpu2016.hero.Human;

public class WarriorTest extends CraftTest {
	@Override
	@BeforeEach
	public void setUp() {
		this.craft = new Warrior(new Human());
	}
}
