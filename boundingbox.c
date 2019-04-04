void boundingbox (SDL_Rect positionpp, SDL_Rect positionobj)
{int done=1, collision=0; 
while(done)
{ if (SDL_PollEvent(&event))
  { switch (event.type)
    { case SDL_KEYDOWN : {
//COLLISION
if ((positionpp.x + positionpp.w < positionobj.x) || (positionpp.x > positionobj.x + positionobj.w) || (positionpp.y + positionpp.h < positionobj.y ) || (positionpp.y > positionobj.y + positionobj.h))
collision = 0;
else {collision =1;
done =0;}
}
