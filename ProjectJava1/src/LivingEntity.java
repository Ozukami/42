import javafx.scene.paint.Color;

public abstract class LivingEntity extends Entity {

	private Floor floor;
	private String name;
	private int expLevel;
	private int expPoints;
	private int expPointsMax;
	private int healthPoints;
	private int healthPointsMax;
	private int energyPoints;
	private int energyPointsMax;
	private int manaPoints;
	private int manaPointsMax;
	private int staminaPoints;
	private int staminaPointsMax;
	private int atkP;
	private int atkM;
	private int defP;
	private int defM;
	private int atkSpeed;
	private int castSpeed;
	private int moveSpeed;
	private int vitality;
	private int strength;
	private int intelligence;
	private int agility;

	public LivingEntity(Color color, double size) {
		super(color, size);
		// TODO Auto-generated constructor stub
	}

	public Floor getFloor() {
		return floor;
	}

	public void setFloor(Floor floor) {
		this.floor = floor;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getExpLevel() {
		return expLevel;
	}

	public void setExpLevel(int expLevel) {
		this.expLevel = expLevel;
	}

	public int getExpPoints() {
		return expPoints;
	}

	public void setExpPoints(int expPoints) {
		this.expPoints = expPoints;
	}

	public int getExpPointsMax() {
		return expPointsMax;
	}

	public void setExpPointsMax(int expPointsMax) {
		this.expPointsMax = expPointsMax;
	}

	public int getHealthPoints() {
		return healthPoints;
	}

	public void setHealthPoints(int healthPoints) {
		this.healthPoints = healthPoints;
	}

	public int getHealthPointsMax() {
		return healthPointsMax;
	}

	public void setHealthPointsMax(int healthPointsMax) {
		this.healthPointsMax = healthPointsMax;
	}

	public int getEnergyPoints() {
		return energyPoints;
	}

	public void setEnergyPoints(int energyPoints) {
		this.energyPoints = energyPoints;
	}

	public int getEnergyPointsMax() {
		return energyPointsMax;
	}

	public void setEnergyPointsMax(int energyPointsMax) {
		this.energyPointsMax = energyPointsMax;
	}

	public int getManaPoints() {
		return manaPoints;
	}

	public void setManaPoints(int manaPoints) {
		this.manaPoints = manaPoints;
	}

	public int getManaPointsMax() {
		return manaPointsMax;
	}

	public void setManaPointsMax(int manaPointsMax) {
		this.manaPointsMax = manaPointsMax;
	}

	public int getStaminaPoints() {
		return staminaPoints;
	}

	public void setStaminaPoints(int staminaPoints) {
		this.staminaPoints = staminaPoints;
	}

	public int getStaminaPointsMax() {
		return staminaPointsMax;
	}

	public void setStaminaPointsMax(int staminaPointsMax) {
		this.staminaPointsMax = staminaPointsMax;
	}

	public int getAtkP() {
		return atkP;
	}

	public void setAtkP(int atkP) {
		this.atkP = atkP;
	}

	public int getAtkM() {
		return atkM;
	}

	public void setAtkM(int atkM) {
		this.atkM = atkM;
	}

	public int getDefP() {
		return defP;
	}

	public void setDefP(int defP) {
		this.defP = defP;
	}

	public int getDefM() {
		return defM;
	}

	public void setDefM(int defM) {
		this.defM = defM;
	}

	public int getAtkSpeed() {
		return atkSpeed;
	}

	public void setAtkSpeed(int atkSpeed) {
		this.atkSpeed = atkSpeed;
	}

	public int getCastSpeed() {
		return castSpeed;
	}

	public void setCastSpeed(int castSpeed) {
		this.castSpeed = castSpeed;
	}

	public int getMoveSpeed() {
		return moveSpeed;
	}

	public void setMoveSpeed(int moveSpeed) {
		this.moveSpeed = moveSpeed;
	}

	public int getVitality() {
		return vitality;
	}

	public void setVitality(int vitality) {
		this.vitality = vitality;
	}

	public int getStrength() {
		return strength;
	}

	public void setStrength(int strength) {
		this.strength = strength;
	}

	public int getIntelligence() {
		return intelligence;
	}

	public void setIntelligence(int intelligence) {
		this.intelligence = intelligence;
	}

	public int getAgility() {
		return agility;
	}

	public void setAgility(int agility) {
		this.agility = agility;
	}

}
