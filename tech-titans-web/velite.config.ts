import { defineConfig, defineCollection, s } from "velite";

// used to generate slug based on path
const processSlugFields = <T extends { slug: string }>(data: T) => ({
  ...data,
  slugAsParams: data.slug.split("/").slice(1).join("/"),
});

const posts = defineCollection({
  name: "Post",
  pattern: "content/**/*.mdx",
  schema: s.object({
    slug: s.path(),
    title: s.string().max(80), // max length of 80 characters for title
    description: s.string().max(500).optional(), // max length of 500 characters for description
    date: s.date(),
    published: s.boolean(), // basically for draft/publish
    body: s.mdx(),
  }).transform(processSlugFields),
});

export default defineConfig({
  root: "content",
  output: {
    data: ".velite",
    assets: "public/static",
    base: "/static/",
    name: "[name].[hash-6][extname]",
    clean: true,
  },
  collections: { posts },
  mdx: {
    rehypePlugins: [],
    remarkPlugins: [],
  },
});