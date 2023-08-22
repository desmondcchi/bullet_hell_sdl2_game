# Level Design Doc

## Rooms
Each level will consist of rooms, which each can have a unique tile map.

So the level is a graph where the nodes are rooms.

```
5 _ 3
|   |
1 - 2 - 6 - 7  
    |
    4 
```

## Tile Map
A room is essentially a tile map. This is an example of a tile map:
```
111111
123541
145231
111111
```

Each number represents a different block that is to be rendered at that respective position.