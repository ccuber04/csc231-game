# Actions
```C++
//override this
Action::perform(Engine& engine)=0;
```
Remember that Actions contain a shared_ptr<Actor> called *actor*

## Results
Performing an *Action* produces a *Result*
bool for succeed or unique_tr<Action> for different action
return these from Action::perform()
- success()-->it worked
- failure()-->give *Actor* another turn
-- Ex: If new position is wall, then failure()
- alternative(AnotherAction{})-->couldn't perform an action then do a different
-- Ex: If new position is door, return alternative(OpenDoor{})

## Moving
Vec and Tiles class
Tiles--Tile& tile = engine.dungeon.tiles(position)

### Vec
(x,y) starting from bottom-left
operator+ and -
```C++
Vec position{10,10}; // (x,y)
```

### Actor
```C++
void change_direction(Vec);
void move_to(Vec)
Vec get_position();
```

## Doors
