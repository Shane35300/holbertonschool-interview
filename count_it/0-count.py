#!/usr/bin/python3
"""recursive function that queries the Reddit API"""
import requests


def count_words(subreddit, word_list, after=None, counts={}):
    """recursive function that queries the Reddit API, parses the title of all
    hot articles, and prints a sorted count of given keywords
    (case-insensitive, delimited by spaces"""

    headers = {'User-Agent': 'HolbertonSchoolTask'}
    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    params = {'limit': 100}

    if after:
        params['after'] = after

    try:
        response = requests.get(url, headers=headers, params=params,
                                allow_redirects=False)
        if response.status_code != 200:
            return

        data = response.json().get('data', {})
        posts = data.get('children', [])
        after = data.get('after', None)

        word_list = [word.lower() for word in word_list]

        for post in posts:
            title = post['data']['title'].lower().split()
            for word in word_list:
                counts[word] = counts.get(word, 0) + title.count(word)

        if after:
            return count_words(subreddit, word_list, after, counts)
        else:
            sorted_counts = sorted(counts.items(),
                                   key=lambda kv: (-kv[1], kv[0]))
            for word, count in sorted_counts:
                if count > 0:
                    print(f"{word}: {count}")
    except Exception as e:
        pass
