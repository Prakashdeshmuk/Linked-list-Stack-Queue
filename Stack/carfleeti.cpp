class Solution {
    public:
    class Car
    {
        public:
        int pos,speed;
        Car(int pos,int speed)
        {
            this->pos = pos;
            this->speed = speed;
        }
    };
    static bool mycomp(Car&a,Car&b)
    {
        return a.pos<b.pos;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car>cars;

        for(int i=0;i<position.size();i++)
        {
            Car car(position[i],speed[i]);
            cars.push_back(car);
        }



        sort(cars.begin(),cars.end(),mycomp);

        stack<float>st;
        for(auto it:cars)
        {
            float time = (target-it.pos)/((float)(it.speed));
            while(!st.empty() && time>=st.top())
            {
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
};