class MapCell
{
private:
    int id;

public:
    MapCell();
    bool IsBlocked();
    void SetId(int newId);
    int GetId();
    ~MapCell();
};
