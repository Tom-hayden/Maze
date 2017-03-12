#pragma once

class Cell {
  public:
    Cell();

    bool Visited() const;
    void MarkVisited();
    bool BottomWall() const;
    bool RightWall() const;
    void BreakBottom();
    void BreakRight();

  private:
    bool bottomwall;
    bool rightwall;
    bool visited;
  };
