import { Post } from "#sites/content";
import { slug } from "github-slugger";

function getPostsByTagSlug(posts: Array<Post>, tag: string) {
  return posts.filter(post => {
    if (!post.tags) return false
    const slugifiedTags = post.tags.map(tag => slug(tag))
    return slugifiedTags.includes(tag)
  })
}

export default getPostsByTagSlug;