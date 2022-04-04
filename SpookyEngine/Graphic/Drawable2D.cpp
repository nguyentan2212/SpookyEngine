#include "Drawable2D.h"

Drawable2D::Drawable2D()
{
	transform = Transform2D();
	renderPosition = transform.GetPosition();
}
