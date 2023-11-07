struct ListNode2{
    int val;
    ListNode2* next;
    ListNode2() : val(0), next(nullptr) {}
    ListNode2(int val) : val(val), next(nullptr) {}
};

class SeatManager {
public:
ListNode2* manager;

    SeatManager(int n) {
        manager = new ListNode2(-1);
        ListNode2* temp = manager;

        for(int i = 1; i <= n; i++){
            ListNode2* rhs = new ListNode2(i);
            temp->next = rhs;
            temp = rhs;
        }
        
    };
    
    int reserve() {
        ListNode2* temp = manager;
        int seat = temp->next->val;
        temp->next = temp->next->next;
        return seat;
    };


    void unreserve(int seatNumber) {
        ListNode2* point = manager;
        if(point->next == nullptr){
            ListNode2* temp = new ListNode2(seatNumber);
            point->next = temp;
        }
        else if(point->next && seatNumber < point->next->val){
            ListNode2* temp = new ListNode2(seatNumber);
            temp->next = point->next;
            point->next = temp;
        }
        else {
            
            while(point->next && point->next->next){
                if(seatNumber > point->next->val && seatNumber < point->next->next->val){
                    ListNode2* temp = new ListNode2(seatNumber);
                    temp->next = point->next->next;
                    point->next->next = temp;
                    break;
                }
                point = point->next;
            }
        }
        
    };
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */