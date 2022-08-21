#ifndef STATUS_H
#define STATUS_H

class Status
{
    private:
        int exitFlag;   // 0 - optimal
                        // 1 - terminated by maxIter
                        // 2 - infeasible

    public:
        Status() { exitFlag = 0; }

        void setExitFlag(int newFlag){ exitFlag = newFlag; }
        int getExitFlag() const { return exitFlag; }
};

#endif // STATUS_H
