select distinct author_id as id from Views 
where author_id = viewer_id group by article_id order by id;