#include "common.h"
#include "graphics.h"

#define FRAME_DELAY 4
#define EXPLOSION_W image_entries[image_LUT_explosion_light_0][0]
#define EXPLOSION_H image_entries[image_LUT_explosion_light_0][1]

ExplosionAnim::ExplosionAnim() : Entity()
{
	counter = 0;
}

ExplosionAnim::~ExplosionAnim()
{
	
}

void ExplosionAnim::activate(int _x, int _y, bool _p)
{
	int w, h;
	Get_Size_Image(image_explosion_light_0, NULL, NULL, &w, &h);
	
	x = _x - w / 2;
	y = _y - h / 2;
	polarity = _p;
	counter = 6 * FRAME_DELAY;
}

void ExplosionAnim::handle()
{
	if(counter)
	{
		// Isn't a drawing candidate
		drawSprite(image_entries[(polarity ? image_LUT_explosion_shadow_0 : image_LUT_explosion_light_0) + (6 * FRAME_DELAY - counter) / FRAME_DELAY], x, y, 0, 0);
		counter--;
	}
}
