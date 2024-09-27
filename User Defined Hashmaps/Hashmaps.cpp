#include <bits/stdc++.h>
#define ll long long
#define BOOST  ios_base::sync_with_stdio(false);    cin.tie(NULL);




using namespace std;




vector<ll> removeDuplicate(ll* a,ll si)

{

    unordered_map<ll,bool> m;

    vector<ll> vect;

    for(ll i=0;i<si;i++)

    {

        if(m.count(a[i])>0)

        {

            continue;

        }

        else

        {

            m[a[i]] = true;

            vect.push_back(a[i]);

        }

    }

    return vect;

}




ll maximumFreNum(ll* a, ll si)

{

    map<ll,ll> m;

    for(ll i=0;i<si;i++)

    {

        m[a[i]]++;

    }

    ll maxFre=INT_MIN, maxEle=INT_MAX;

    for(auto i:m)

    {

        if(i.second>maxFre)

        {

            maxFre = i.second;

            maxEle = i.first;

        }

    }

    return maxEle;

}




vector<ll> arrayIntersection(ll* a, ll n, ll* b , ll m)

{

    map<ll,ll> m1;

    vector<ll> vect;

    if(n<m)

    {

        for(ll i=0;i<n;i++)

        {

            m1[a[i]]++;

        }

        for(ll i=0;i<m;i++)

        {

            if(m1[b[i]]>0)

            {

                vect.push_back(b[i]);

                m1[b[i]]--;

            }

        }

    }

    else

    {

        for(ll i=0;i<m;i++)

        {

            m1[b[i]]++;

        }

        for(ll i=0;i<n;i++)

        {

            if(m1[a[i]]>0)

            {

                vect.push_back(a[i]);

                m1[a[i]]--;

            }

        }

    }

    sort(vect.begin(), vect.end());

    return vect;

}




ll pairtToSum0(ll* a, ll si)

{

    map<ll,ll> m,ans;

    for(ll i=0;i<si;i++) {

        m[a[i]]++;

        if(m.count(-a[i])>0)

        {

            ans[abs(a[i])] = m[a[i]]*m[-a[i]];

        }

    }

    ll sum=0;

    for(auto i:ans)

    {

        sum+=i.second;

    }

    return sum;

}




// User Defined Hashmaps




template< typename  v>

class MapNode{

public:

    string key;

    v value;

    MapNode* next;

    MapNode(string key, v value)

    {

        this->key = key;

        this->value = value;

        next = nullptr;

    }

    ~MapNode()

    {

        delete next;

    }

};




template <typename v>

class ourMap{

    MapNode<v>** buckets;

    ll count_size;

    ll numBuckets;

public:

    ourMap()

    {

        count_size=0;

        numBuckets=5;

        buckets = new MapNode<v>* [numBuckets];

        for(ll i=0;i<numBuckets;i++)

        {

            buckets[i] = nullptr;

        }

    }

    ~ourMap(){

        for(ll i=0;i<numBuckets;i++)

        {

            delete buckets[i];

        }

        delete [] buckets;

    }




private:




    ll getBucketIndex(string key)

    {

        ll hashCode = 0;

        ll curCoefficient = 1;

        for(ll i=key.length()-1;i>=0;i--)

        {

            hashCode+= key[i]*curCoefficient;

            hashCode = hashCode%numBuckets;

            curCoefficient*=37;

            curCoefficient = curCoefficient%numBuckets;

        }

        return hashCode%numBuckets;

    }




    void rehash()

    {

        MapNode<v>** temp = buckets;

        buckets = new MapNode<v>*[numBuckets*2];

        for(ll i=0;i<2*numBuckets;i++)

        {

            buckets[i] = nullptr;

        }

        ll oldNumBuckets = numBuckets;

        numBuckets*=2;

        count_size = 0;

        for(ll i=0;i<oldNumBuckets;i++)

        {

            MapNode<v>* tempNode = temp[i];

            while(tempNode!=nullptr)

            {

                string key = tempNode->key;

                v val = tempNode->value;

                insert(key,val);

                tempNode = tempNode->next;

            }

        }




        for(ll i=0;i<oldNumBuckets;i++)

        {

            delete temp[i];

        }




        delete [] temp;

    }




public:

    ll size()

    {

        return count_size;

    }




    void insert(string key, v val)

    {

        ll bucketIndex = getBucketIndex(key);

        MapNode<v>* head = buckets[bucketIndex];

        MapNode<v>* temp = head;

        while(temp!=nullptr)

        {

            if(temp->key==key)

            {

                temp->value = val;

                return;

            }

        }

        MapNode<v>* newNode = new MapNode<v>(key,val);

        newNode->next = head;

        buckets[bucketIndex] = newNode;

        count_size++;

        double loadFactor = (1.0*count_size)/numBuckets;

        if(loadFactor>0.7)

        {

            rehash();

        }

    }




    v getValue(string key)

    {

        ll bucketIndex = getBucketIndex(key);

        MapNode<v>* head = buckets[bucketIndex];

        MapNode<v>* temp = head;

        while(temp!=nullptr)

        {

            if(temp->key == key)

            {

                return temp->value;

            }

            temp = temp->next;

        }

        return 0;  // We can do v val = 0 and then return it but this is also correct it will automatically be converted into that type.

    }




    v remove(string key)

    {

        ll bucketIndex = getBucketIndex(key);

        MapNode<v>* head = buckets[bucketIndex];

        MapNode<v>* temp = head;

        MapNode<v>* prev = nullptr;

        v val = 0;

        while(temp!=nullptr)

        {

            if(temp->key == key)

            {

                if(prev == nullptr)

                {

                    buckets[bucketIndex] = head->next;

                }

                else {

                    prev->next = temp->next;

                }

                val = temp->value;

                temp->next = nullptr;

                delete temp;

                count_size--;

                return val;

            }

            prev = temp;

            temp = temp->next;

        }

        return val;

    }




    double getLoadFactor()

    {

        return (1.0*count_size)/numBuckets;

    }




};




void testMap()

{

    ourMap<ll> map;

    for(ll i=0;i<10;i++)

    {

        string key = "abc";

        char c = '0' + i;

        key = key + c;

        ll value = 1 + i;

        map.insert(key,value);

        cout<<map.getLoadFactor()<<endl;

    }

    for(ll i=0;i<10;i++)

    {

        string key = "abc";

        char c = '0' + i;

        key = key + c;

        ll value = 1 + i;

        cout<<key<<" : "<<map.getValue(key)<<endl;

    }

    cout<<map.size()<<endl;

    cout<<"Now deleting values\n";

    map.remove("abc3");

    map.remove("abc9");

    for(ll i=0;i<10;i++)

    {

        string key = "abc";

        char c = '0' + i;

        key = key + c;

        ll value = 1 + i;

        cout<<key<<" : "<<map.getValue(key)<<endl;

    }

    cout<<map.size()<<endl;

}




string extractUniqueChar(string str)

{

    string ans_str = "";

    map<char,bool> m;

    for(auto i:str)

    {

        if(m.count(i)==0) {

            m[i] = true;

            ans_str += i;

        }

    }

    return ans_str;

}







vector<ll> longConsecutiveSequence(vector<ll> vect)

{

    map<ll,pair<bool,ll>> m;

    vector<ll> ans;

    ll k=0;

    for(auto i:vect)

    {

        m[i].first = true;

        m[i].second = k;

        k++;

    }

    ll start = INT_MAX, end = INT_MIN,lStreak=0;

    for(auto i:vect)

    {

        ll curEnd = i, curStart = i,curStreak=1;

        m[i].first = false;

        while(m.count(curStart-1)>0 and m[curStart-1].first)

        {

            curStart -=1;

            curStreak+=1;

            m[curStart].first = false;

        }

        while(m.count(curEnd+1)>0 and m[curEnd+1].first)

        {

            curEnd = curEnd+1;

            m[curEnd].first = false;

            curStreak+=1;

        }

        if(curStreak>lStreak or(curStreak==lStreak and m[curStart].second<m[start].second))

        {

            lStreak = curStreak;

            start = curStart;

            end = curEnd;

        }

    }

    if(start==end)

    {

        ans.push_back(start);

    }

    else

    {

        ans.push_back(start);

        ans.push_back(end);




    }

    return ans;

}







ll pairWithDifferenceK(vector<ll> vect, ll k)

{

    map<ll,ll> m;

    for(auto i:vect) {

        m[i]++;

    }

    ll sum = 0;

    if(k!=0) {

        for (auto &i:m) {

            if (m.count(i.first - k) > 0) {

                sum += i.second * (m[i.first - k]);

            }

            if (m.count(i.first + k) > 0) {

                sum += i.second * (m[i.first + k]);

            }

            i.second = 0;

        }

    }

    else

    {

        for(auto i:m)

        {

            sum+= (i.second)*(i.second-1)/2;

        }

    }

    return  sum;

}




ll longestSubsetZeroSum(vector<ll> vect)

{

    map<ll,ll> m;

    ll sum = 0;

    ll maxLen = INT_MIN;

    for(ll i=0;i<vect.size();i++)

    {

        ll curLen = 0;

        sum+=vect[i];

        if(sum==0)

        {

            curLen = i+1;

        }

        if(m.count(sum)>0)

        {

            curLen = max(i-m[sum],curLen);

        }

        else

        {

            m[sum] = i;

        }




        maxLen = max(maxLen,curLen);

    }

    return maxLen;

}




int main()

{




    BOOST;




    cout<<fixed;

    ll n;

    cin>>n;

    vector<ll> vect(n);

    for(ll i=0;i<n;i++)

    {

        cin>>vect[i];

    }

    cout<<longestSubsetZeroSum(vect);




    return 0;

}



