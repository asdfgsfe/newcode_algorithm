【设计题】今日头条会根据用户的浏览行为、内容偏好等信息，为每个用户抽象出一个标签化的用户画像，
用于内容推荐。用户画像的存储、高并发访问，是推荐系统的重要环节之一。
现在请你给出一个用户画像存储、访问方案，设计的时候请考虑一下几个方面：

用户画像如何存储

如何保证在线高并发、低延迟地访问

机器宕机、负载均衡问题

如果用户增长很快，在你的方案下，该如何做扩容