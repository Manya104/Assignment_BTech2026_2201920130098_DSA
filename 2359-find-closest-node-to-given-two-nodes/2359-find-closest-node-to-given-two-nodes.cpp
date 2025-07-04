class Solution
{
public:
    template <size_t>
    static std::vector<int>& static_vector()
    {
        static std::vector<int> v;
        return v;
    }

    struct WalkInfo
    {
        int intersection = -1;
        int cycle_point = -1;
    };

    int closestMeetingNode(std::vector<int>& edges, int node1, int node2)
    {
        auto walk = [&edges]<typename TV>(
                        std::vector<int>& distances,
                        int start,
                        const TV& another_dist)
        {
            {
                size_t ps = distances.size();
                distances.resize(edges.size() + 1, -1);
                std::fill_n(
                    distances.begin(),
                    std::min(ps, distances.size()),
                    -1);
            }

            int intersection = -1;
            int cycle_point = -1;
            for (int i = start, dist = 0; i != -1; i = edges[i], ++dist)
            {
                if (distances[i] != -1)
                {
                    cycle_point = i;
                    break;
                }

                distances[i] = dist;

                if constexpr (!std::same_as<int, TV>)
                {
                    if (intersection == -1 && another_dist[i] != -1)
                    {
                        intersection = i;
                    }
                }
            }

            return WalkInfo{intersection, cycle_point};
        };

        int r = -1, rcond = -1;

        auto& distances1 = static_vector<0>();
        auto w1 = walk(distances1, node1, 0);
        auto& distances2 = static_vector<1>();
        auto w2 = walk(distances2, node2, distances1);

        auto consider = [&](int node)
        {
            if (node == -1) return;
            int d1 = distances1[node];
            int d2 = distances2[node];
            if (d1 == -1 || d2 == -1) return;
            const int cond = std::max(d1, d2);
            if (r == -1)
            {
                r = node, rcond = cond;
                return;
            }

            if (cond > rcond) return;

            if (cond == rcond)
            {
                r = std::min(r, node);
            }
            else
            {
                r = node, rcond = cond;
            }
        };

        consider(node1);
        consider(node2);
        consider(w1.intersection);
        consider(w1.cycle_point);
        consider(w2.intersection);
        consider(w2.cycle_point);

        return r;
    }
};