#include "LinkedList.h"
#include "RenderLayer.h"
#pragma once

using namespace std;

class RenderManager
{

public:

	RenderManager()
	{
		instance = this;
	}

	~RenderManager()
	{
	}

	RenderManager* getInstance()
	{
		return instance;
	}

	void drawLayers()
	{

	}

private:
	RenderManager* instance = NULL;
	LinkedList<RenderLayer>* layers = new LinkedList<RenderLayer>();

};

