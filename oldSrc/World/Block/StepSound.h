#pragma once

#include <string>

class StepSound {
public:
	std::string field_1678_a;
	float field_1677_b;
	float field_1679_c;

	StepSound(std::string var1, float var2, float var3) {
		this->field_1678_a = var1;
		this->field_1677_b = var2;
		this->field_1679_c = var3;
	}

	float getVolume() {
		return this->field_1677_b;
	}

	float getPitch() {
		return this->field_1679_c;
	}

	virtual std::string stepSoundDir() const {
		return "step." + this->field_1678_a;
	}

	virtual std::string func_1145_d() const {
		return "step." + this->field_1678_a;
	}
};


class StepSoundSand : public StepSound 
{
public:
	StepSoundSand(std::string var1, float var2, float var3) : StepSound(var1, var2, var3)
    {
	}

	std::string stepSoundDir() const override {
		return "step.gravel";
	}
};

class StepSoundStone : public StepSound 
{
public:
	StepSoundStone(std::string var1, float var2, float var3) : StepSound(var1, var2, var3)
    {
	}

	std::string stepSoundDir() const override {
		return "random.glass";
	}
};
