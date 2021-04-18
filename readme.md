## 测例

这个是 pi 这个 verifying compiler 的测例仓库。

所有的测例分为 partial correctness 和 termination 两大类，分别放在两个文件夹下面。

每个文件夹里有一个 `answers.json`，是这个文件夹里所有测例的答案，其格式如下

```json
[
    {
        "filename": <filename>,
        "answer": "VERIFIED" or "UNVERIFIED",
        "timeout": <time> (seconds)
    },
    ...
]
```

## 安装

Python >= 3.8

```bash

```

