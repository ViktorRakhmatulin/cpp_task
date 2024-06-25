import math
import heapq

class Point:
    def __init__(self, x, y, penalty):
        self.x = x
        self.y = y
        self.penalty = penalty

def calculate_travel_time(a, b, speed=2.0):
    return math.sqrt((b.x - a.x) ** 2 + (b.y - a.y) ** 2) / speed

def dijkstra(points):
    n = len(points)
    graph = [[] for _ in range(n)]

    # graph(cost, target)
    # 
    for i in range(n):
        for j in range(i + 1, n):
            travel_time = calculate_travel_time(points[i], points[j])
            if j == i + 1:
                graph[i].append((travel_time + 10, j))
            else:
                penalties = sum(points[k].penalty for k in range(i + 1, j))
                graph[i].append((travel_time + 10 + penalties, j))
    
    dist = [float('inf')] * n
    dist[0] = 0.0
    priority_queue = [(0.0, 0)]

    while priority_queue:
        d, u = heapq.heappop(priority_queue)

        if d > dist[u]:
            continue

        for weight, v in graph[u]:
            if dist[u] + weight < dist[v]:
                dist[v] = dist[u] + weight
                heapq.heappush(priority_queue, (dist[v], v))

    return dist[-1]

def main():
    try:
        with open("input.txt", "r") as infile:
            while True:
                line = infile.readline().strip()
                if not line:
                    break

                N = int(line)
                if N == 0:
                    break

                points = [Point(0, 0, 0)]
                for _ in range(N):
                    x, y, penalty = map(int, infile.readline().strip().split())
                    points.append(Point(x, y, penalty))

                points.append(Point(100, 100, 0))

                result = dijkstra(points)
                print(f"{result:.3f}")

    except FileNotFoundError:
        print("Error: Unable to open input file.")
        return

if __name__ == "__main__":
    main()
