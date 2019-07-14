# icpc2019jap

## https://storage.googleapis.com/icpcsec/2019-domestic/ja/contest/all_ja.html

### 京都産業大学 チーム Arattarius で出場しました。

４完　３０位で国内予選突破したの嬉しすぎました。

先輩に感謝感謝です。

とりあえず、自分で解いた分(コンテスト後含め)を載せておきます。

### 個人的な講評

#### A問題

簡単。縦に見るだけ。

#### B問題

文字が複数あったら〜とか考えたけど、文字の重複はないらしいので簡単。

去年が難しすぎたせいでとても簡単になってる。

A問題って言われてもおかしくないレベル。

#### E問題

時間はかかったけど、やってて楽しい問題でした（本当かよ）

方針としては、１つのピースから８つの状態を作る。これを６ピースぶん行う。

あとは、立方体にするために１つずつピースを固定していけばいい。

計算量は、O(6!x8)でやってます。１つを固定する発想がなかったのと、そうしなくても十分高速に行けると思いました。

３次元配列を埋める時、キャッシュとして使ってたピースを入れてる２次元配列の添字の場合分けが必要なことに気づけなかったのが痛いです。

あと添字ミスでバグってました。

入力nに対して、配列の末尾はn-1なのを忘れてた...

本番の方針はあってたけど、詰めが甘かったので精進します。

コードは完成してます。


