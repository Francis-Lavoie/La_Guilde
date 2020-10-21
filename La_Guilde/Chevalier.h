#pragma once
#include "Aventurier.h"
class Chevalier : public Aventurier
{
public:
	string to_string() override;
	Chevalier();
	~Chevalier();
};

